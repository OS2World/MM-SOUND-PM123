#ifndef fooformathfoo
#define fooformathfoo

/***
  This file is part of PulseAudio.

  Copyright 2011 Intel Corporation
  Copyright 2011 Collabora Multimedia
  Copyright 2011 Arun Raghavan <arun.raghavan@collabora.co.uk>

  PulseAudio is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published
  by the Free Software Foundation; either version 2.1 of the License,
  or (at your option) any later version.

  PulseAudio is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with PulseAudio; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
  USA.
***/

#include <pulse/cdecl.h>
#include <pulse/gccmacro.h>
#include <pulse/proplist.h>
#include <pulse/sample.h>
#include <pulse/channelmap.h>

PA_C_DECL_BEGIN

/**< Represents the type of encoding used in a stream or accepted by a sink. \since 1.0 */
typedef enum pa_encoding {
    PA_ENCODING_ANY,
    /**< Any encoding format, PCM or compressed */

    PA_ENCODING_PCM,
    /**< Any PCM format */

    PA_ENCODING_AC3_IEC61937,
    /**< AC3 data encapsulated in IEC 61937 header/padding */

    PA_ENCODING_EAC3_IEC61937,
    /**< EAC3 data encapsulated in IEC 61937 header/padding */

    PA_ENCODING_MPEG_IEC61937,
    /**< MPEG-1 or MPEG-2 (Part 3, not AAC) data encapsulated in IEC 61937 header/padding */

    PA_ENCODING_DTS_IEC61937,
    /**< DTS data encapsulated in IEC 61937 header/padding */

    PA_ENCODING_MAX,
    /**< Valid encoding types must be less than this value */

    PA_ENCODING_INVALID = -1,
    /**< Represents an invalid encoding */
} pa_encoding_t;

/** Returns a printable string representing the given encoding type. \since 1.0 */
const char *pa_encoding_to_string(pa_encoding_t e) PA_GCC_CONST;

/**< Represents the format of data provided in a stream or processed by a sink. \since 1.0 */
typedef struct pa_format_info {
    pa_encoding_t encoding;
    /**< The encoding used for the format */

    pa_proplist *plist;
    /**< Additional encoding-specific properties such as sample rate, bitrate, etc. */
} pa_format_info;

/**< Allocates a new \a pa_format_info structure. Clients must initialise at least the encoding field themselves. */
pa_format_info* pa_format_info_new(void);

/**< Returns a new \a pa_format_info struct and representing the same format as \a src */
pa_format_info* pa_format_info_copy(const pa_format_info *src);

/**< Frees a \a pa_format_info structure */
void pa_format_info_free(pa_format_info *f);

/** Returns non-zero when the format info structure is valid */
int pa_format_info_valid(const pa_format_info *f);

/** Returns non-zero when the format info structure represents a PCM (i.e. uncompressed data) format */
int pa_format_info_is_pcm(const pa_format_info *f);

/** Returns non-zero if the format represented \a first is a subset of
 * the format represented by \second. This means that \a second must
 * have all the fields that \a first does, but the reverse need not
 * be true. This is typically expected to be used to check if a
 * stream's format is compatible with a given sink. In such a case,
 * \a first would be the sink's format and \a second would be the
 * stream's.*/
int pa_format_info_is_compatible(pa_format_info *first, pa_format_info *second);

/** Maximum required string length for
 * pa_format_info_snprint(). Please note that this value can change
 * with any release without warning and without being considered API
 * or ABI breakage. You should not use this definition anywhere where
 * it might become part of an ABI. \since 1.0 */
#define PA_FORMAT_INFO_SNPRINT_MAX 256

/** Return a human-readable string representing the given format. \since 1.0 */
char *pa_format_info_snprint(char *s, size_t l, const pa_format_info *f);

/** Sets an integer property on the given format info */
void pa_format_info_set_prop_int(pa_format_info *f, const char *key, int value);
/** Sets a property with a list of integer values on the given format info */
void pa_format_info_set_prop_int_array(pa_format_info *f, const char *key, const int *values, int n_values);
/** Sets a property which can have any value in a given integer range on the given format info */
void pa_format_info_set_prop_int_range(pa_format_info *f, const char *key, int min, int max);
/** Sets a string property on the given format info */
void pa_format_info_set_prop_string(pa_format_info *f, const char *key, const char *value);
/** Sets a property with a list of string values on the given format info */
void pa_format_info_set_prop_string_array(pa_format_info *f, const char *key, const char **values, int n_values);

/** Convenience method to set the sample format as a property on the given format */
void pa_format_info_set_sample_format(pa_format_info *f, pa_sample_format_t sf);
/** Convenience method to set the sampling rate as a property on the given format */
void pa_format_info_set_rate(pa_format_info *f, int rate);
/** Convenience method to set the number of channels as a property on the given format */
void pa_format_info_set_channels(pa_format_info *f, int channels);
/** Convenience method to set the channel map as a property on the given format */
void pa_format_info_set_channel_map(pa_format_info *f, const pa_channel_map *map);

PA_C_DECL_END

#endif
