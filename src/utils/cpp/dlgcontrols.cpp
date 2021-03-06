/*
 * Copyright 2007-2008 Marcel M�eller
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *    3. The name of the author may not be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#define  INCL_PM
#include "dlgcontrols.h"

#include <os2.h>

#include <stdlib.h>
#include <string.h>

#include <debuglog.h>


USHORT RadioButton::CheckID() const
{
  const HWND parent = WinQueryWindow(Hwnd, QW_PARENT);
  HWND cur = WinEnumDlgItem(parent, Hwnd, EDI_FIRSTGROUPITEM);
  char classname[8];
  do
  { if ( WinQueryClassName(cur, sizeof classname, classname) == 2
      && classname[0] == '#' && classname[1] == '3' // is WC_BUTTON
      && WinSendMsg(cur, BM_QUERYCHECK, 0, 0) )
      return WinQueryWindowUShort(cur, QWS_ID);
    cur = WinQueryWindow(cur, QW_NEXT);
  } while (cur && !(WinQueryWindowULong(cur, QWL_STYLE) & WS_GROUP));
  return 0;
}

void RadioButton::EnableAll(bool enabled)
{
  const HWND parent = WinQueryWindow(Hwnd, QW_PARENT);
  HWND cur = WinEnumDlgItem(parent, Hwnd, EDI_FIRSTGROUPITEM);
  char classname[8];
  do
  { if ( WinQueryClassName(cur, sizeof classname, classname) == 2
      && classname[0] == '#' && classname[1] == '3' ) // is WC_BUTTON
      PMRASSERT(WinEnableWindow(cur, enabled));
    cur = WinQueryWindow(cur, QW_NEXT);
  } while (cur && !(WinQueryWindowULong(cur, QWL_STYLE) & WS_GROUP));
}

void RadioButton::UncheckAll()
{
  const HWND parent = WinQueryWindow(Hwnd, QW_PARENT);
  HWND cur = WinEnumDlgItem(parent, Hwnd, EDI_FIRSTGROUPITEM);
  char classname[8];
  do
  { if ( WinQueryClassName(cur, sizeof classname, classname) == 2
      && classname[0] == '#' && classname[1] == '3' ) // is WC_BUTTON
      WinSendMsg(Hwnd, BM_SETCHECK, MPFROMSHORT(FALSE), 0);
    cur = WinQueryWindow(cur, QW_NEXT);
  } while (cur && !(WinQueryWindowULong(cur, QWL_STYLE) & WS_GROUP));
}

void ListBox::InsertItems(const char*const* items, unsigned count, int where)
{ LBOXINFO lbi = {0};
  lbi.lItemIndex = where;
  lbi.ulItemCount = count;
  PMXASSERT(WinSendMsg(Hwnd, LM_INSERTMULTITEMS, MPFROMP(&lbi), MPFROMP(items)), == MRFROMLONG(count));
}

void ComboBox::InsertItems(const char*const* items, unsigned count, int where)
{ while (count--)
  { InsertItem(*items++, where);
    if (where >= 0)
      ++where;
  }
}

xstring ListBox::ItemText(int i) const
{ xstring result;
  if (i != LIT_NONE)
  { SHORT len = SHORT1FROMMR(WinSendMsg(Hwnd, LM_QUERYITEMTEXTLENGTH, MPFROMSHORT(i), 0));
    PMASSERT(len != LIT_ERROR);
    char* cp = result.allocate(len);
    WinSendMsg(Hwnd, LM_QUERYITEMTEXT, MPFROM2SHORT(i, len+1), MPFROMP(cp));
  }
  return result;
}

void SpinButton::SetLimits(LONG low, LONG high, USHORT len) const
{ PMRASSERT(WinSendMsg(Hwnd, SPBM_SETLIMITS, MPFROMLONG(high), MPFROMLONG(low)));
  PMRASSERT(WinSendMsg(Hwnd, SPBM_SETTEXTLIMIT, MPFROMSHORT(len), 0));
}

LONG SpinButton::Value() const
{ LONG ret;
  PMRASSERT(WinSendMsg(Hwnd, SPBM_QUERYVALUE, MPFROMP(&ret), MPFROM2SHORT(0, SPBQ_DONOTUPDATE)));
  return ret;
}

