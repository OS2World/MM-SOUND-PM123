/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2007             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

 function: stdio-based convenience library for opening/seeking/decoding
 last mod: $Id: vorbisfile.h 17182 2010-04-29 03:48:32Z xiphmont $

 ********************************************************************/

#ifndef _OV_FILE_H_
#define _OV_FILE_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdio.h>
#include "codec.h"

/* The function prototypes for the callbacks are basically the same as for
 * the stdio functions fread, fseek, fclose, ftell.
 * The one difference is that the FILE * arguments have been replaced with
 * a void * - this is to be used as a pointer to whatever internal data these
 * functions might need. In the stdio case, it's just a FILE * cast to a void *
 *
 * If you use other functions, check the docs for these functions and return
 * the right values. For seek_func(), you *MUST* return -1 if the stream is
 * unseekable
 */
typedef struct {
  size_t DLLENTRYP(read_func)  (void *ptr, size_t size, size_t nmemb, void *datasource);
  int    DLLENTRYP(seek_func)  (void *datasource, ogg_int64_t offset, int whence);
  int    DLLENTRYP(close_func) (void *datasource);
  ogg_int64_t DLLENTRYP(tell_func)  (void *datasource);
} ov_callbacks;


/* a few sets of convenient callbacks, especially for use under
 * Windows where ov_open_callbacks() should always be used instead of
 * ov_open() to avoid problems with incompatible crt.o version linking
 * issues. */

static int DLLENTRY _ov_header_fseek_wrap(FILE *f,ogg_int64_t off,int whence){
  if(f==NULL)return(-1);

#ifdef __MINGW32__
  return fseeko64(f,off,whence);
#elif defined (_WIN32)
  return _fseeki64(f,off,whence);
#else
  return fseek(f,off,whence);
#endif
}

static ogg_int64_t DLLENTRY _ov_header_ftell_wrap(FILE *f){
  if(f==NULL)return(-1);

#ifdef __MINGW32__
  return ftello64(f);
#elif defined (_WIN32)
  return _ftelli64(f);
#else
  return ftell(f);
#endif
}

#ifndef OV_EXCLUDE_STATIC_CALLBACKS

/* These structs below (OV_CALLBACKS_DEFAULT etc) are defined here as
 * static data. That means that every file which includes this header
 * will get its own copy of these structs whether it uses them or
 * not unless it #defines OV_EXCLUDE_STATIC_CALLBACKS.
 * These static symbols are essential on platforms such as Windows on
 * which several different versions of stdio support may be linked to
 * by different DLLs, and we need to be certain we know which one
 * we're using (the same one as the main application).
 */

static ov_callbacks OV_CALLBACKS_DEFAULT = {
  (size_t DLLENTRYPF()(void *, size_t, size_t, void *))  fread,
  (int DLLENTRYPF()(void *, ogg_int64_t, int))           _ov_header_fseek_wrap,
  (int DLLENTRYPF()(void *))                             fclose,
  (ogg_int64_t DLLENTRYPF()(void *))                     _ov_header_ftell_wrap,
};

static ov_callbacks OV_CALLBACKS_NOCLOSE = {
  (size_t DLLENTRYPF()(void *, size_t, size_t, void *))  fread,
  (int DLLENTRYPF()(void *, ogg_int64_t, int))           _ov_header_fseek_wrap,
  (int DLLENTRYPF()(void *))                             NULL,
  (ogg_int64_t DLLENTRYPF()(void *))                     _ov_header_fseek_wrap,
};

static ov_callbacks OV_CALLBACKS_STREAMONLY = {
  (size_t DLLENTRYPF()(void *, size_t, size_t, void *))  fread,
  (int DLLENTRYPF()(void *, ogg_int64_t, int))           NULL,
  (int DLLENTRYPF()(void *))                             fclose,
  (ogg_int64_t DLLENTRYPF()(void *))                     NULL
};

static ov_callbacks OV_CALLBACKS_STREAMONLY_NOCLOSE = {
  (size_t DLLENTRYPF()(void *, size_t, size_t, void *))  fread,
  (int DLLENTRYPF()(void *, ogg_int64_t, int))           NULL,
  (int DLLENTRYPF()(void *))                             NULL,
  (ogg_int64_t DLLENTRYPF()(void *))                     NULL
};

#endif

#define  NOTOPEN   0
#define  PARTOPEN  1
#define  OPENED    2
#define  STREAMSET 3
#define  INITSET   4

typedef struct OggVorbis_File {
  void            *datasource; /* Pointer to a FILE *, etc. */
  int              seekable;
  ogg_int64_t      offset;
  ogg_int64_t      end;
  ogg_sync_state   oy;

  /* If the FILE handle isn't seekable (eg, a pipe), only the current
     stream appears */
  int              links;
  ogg_int64_t     *offsets;
  ogg_int64_t     *dataoffsets;
  long            *serialnos;
  ogg_int64_t     *pcmlengths; /* overloaded to maintain binary
                                  compatibility; x2 size, stores both
                                  beginning and end values */
  vorbis_info     *vi;
  vorbis_comment  *vc;

  /* Decoding working state local storage */
  ogg_int64_t      pcm_offset;
  int              ready_state;
  long             current_serialno;
  int              current_link;

  double           bittrack;
  double           samptrack;

  ogg_stream_state os; /* take physical pages, weld into a logical
                          stream of packets */
  vorbis_dsp_state vd; /* central working state for the packet->PCM decoder */
  vorbis_block     vb; /* local working space for packet->PCM decode */

  ov_callbacks callbacks;

} OggVorbis_File;


extern int DLLENTRY ov_clear(OggVorbis_File *vf);
extern int DLLENTRY ov_fopen(const char *path,OggVorbis_File *vf);
extern int DLLENTRY ov_open(FILE *f,OggVorbis_File *vf,const char *initial,long ibytes);
extern int DLLENTRY ov_open_callbacks(void *datasource, OggVorbis_File *vf,
                const char *initial, long ibytes, ov_callbacks callbacks);

extern int DLLENTRY ov_test(FILE *f,OggVorbis_File *vf,const char *initial,long ibytes);
extern int DLLENTRY ov_test_callbacks(void *datasource, OggVorbis_File *vf,
                const char *initial, long ibytes, ov_callbacks callbacks);
extern int DLLENTRY ov_test_open(OggVorbis_File *vf);

extern long DLLENTRY ov_bitrate(OggVorbis_File *vf,int i);
extern long DLLENTRY ov_bitrate_instant(OggVorbis_File *vf);
extern long DLLENTRY ov_streams(OggVorbis_File *vf);
extern long DLLENTRY ov_seekable(OggVorbis_File *vf);
extern long DLLENTRY ov_serialnumber(OggVorbis_File *vf,int i);

extern ogg_int64_t DLLENTRY ov_raw_total(OggVorbis_File *vf,int i);
extern ogg_int64_t DLLENTRY ov_pcm_total(OggVorbis_File *vf,int i);
extern double DLLENTRY ov_time_total(OggVorbis_File *vf,int i);

extern int DLLENTRY ov_raw_seek(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_pcm_seek(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_pcm_seek_page(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_time_seek(OggVorbis_File *vf,double pos);
extern int DLLENTRY ov_time_seek_page(OggVorbis_File *vf,double pos);

extern int DLLENTRY ov_raw_seek_lap(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_pcm_seek_lap(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_pcm_seek_page_lap(OggVorbis_File *vf,ogg_int64_t pos);
extern int DLLENTRY ov_time_seek_lap(OggVorbis_File *vf,double pos);
extern int DLLENTRY ov_time_seek_page_lap(OggVorbis_File *vf,double pos);

extern ogg_int64_t DLLENTRY ov_raw_tell(OggVorbis_File *vf);
extern ogg_int64_t DLLENTRY ov_pcm_tell(OggVorbis_File *vf);
extern double DLLENTRY ov_time_tell(OggVorbis_File *vf);

extern vorbis_info* DLLENTRY ov_info(OggVorbis_File *vf,int link);
extern vorbis_comment* DLLENTRY ov_comment(OggVorbis_File *vf,int link);

extern long DLLENTRY ov_read_float(OggVorbis_File *vf,float ***pcm_channels,int samples,
                          int *bitstream);
extern long DLLENTRY ov_read_filter(OggVorbis_File *vf,char *buffer,int length,
                          int bigendianp,int word,int sgned,int *bitstream,
                          void (*filter)(float **pcm,long channels,long samples,void *filter_param),void *filter_param);
extern long DLLENTRY ov_read(OggVorbis_File *vf,char *buffer,int length,
                    int bigendianp,int word,int sgned,int *bitstream);
extern int DLLENTRY ov_crosslap(OggVorbis_File *vf1,OggVorbis_File *vf2);

extern int DLLENTRY ov_halfrate(OggVorbis_File *vf,int flag);
extern int DLLENTRY ov_halfrate_p(OggVorbis_File *vf);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

