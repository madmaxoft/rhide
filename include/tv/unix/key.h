/* Linux keyboard handler routines header.
   Copyright by Salvador E. Tropea (SET) (2001)
   Covered by the GPL license. */
#ifndef LINUXKEY_HEADER_INCLUDED
#define LINUXKEY_HEADER_INCLUDED
struct TEvent;

// A class to encapsulate the globals, all is static!
class TGKeyUNIX : public TGKey
{
public:
 TGKeyUNIX() {};

 // Function replacements
 static void     Suspend();
 static void     Resume();
 static int      KbHit();
 static void     Clear();
 static ushort   GKey();
 static unsigned GetShiftState();
 static void     FillTEvent(TEvent &e);
 static void     SetKbdMapping(int version);

 // Setup the pointers to point our members
 static void     Init();

protected:
 // Specific for this driver
 static void     GetRaw(void);
 static int      Abstract;
 static char     ascii;
 static ushort   sFlags;
 static KeyType  rawCode;
};
#endif // LINUXKEY_HEADER_INCLUDED
