#define DEBUGMODE
// -*- mode:C++; tab-width: 4 -*-
#include <tv/configtv.h>

#define Uses_TScreen
#define Uses_TEvent
#define Uses_TGKey
#include <tv.h>

#include <tv/alcon/key.h>
#define Uses_AlCon_conio
#include <tv/alcon/alcon.h>


/*****************************************************************************

  TGKeyAlcon keyboard stuff.

*****************************************************************************/

unsigned TGKeyAlcon::Symbol;
uchar    TGKeyAlcon::Scan;
unsigned TGKeyAlcon::Flags;

void TGKeyAlcon::Init()
{
    TGKey::kbhit = KbHit;
    TGKey::clear = Clear;
    TGKey::gkey = GKey;
    TGKey::fillTEvent = FillTEvent;
//  TGKey::getShiftState=GetShiftState;
}

int TGKeyAlcon::KbHit()
{
    return AlCon_KbHit();
}

void TGKeyAlcon::Clear()
{
    AlCon_ClearKeyBuf();
}

ushort TGKeyAlcon::GKey()
{
    return AlCon_GetKey(&Symbol, &Scan, &Flags);
}

void TGKeyAlcon::FillTEvent(TEvent &e)
{
    ushort Abstract=GKey();
    e.keyDown.charScan.charCode=((Flags & kbAltLCode) && (Symbol<128)) ? 0 : Symbol;
    e.keyDown.charScan.scanCode=Scan;
    e.keyDown.raw_scanCode=Scan;
    e.keyDown.keyCode=Abstract;
    e.keyDown.shiftState=0;
    // TODO: fill the shiftState correctly.
    //e.keyDown.shiftState=kbFlags;

    // TODO: Unicode? Yeah right.
    //e.keyDown.charCode=Unicode; // Should I do the same as with Symbol?
    e.what=evKeyDown;
}

