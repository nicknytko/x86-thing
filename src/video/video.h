#ifndef VIDEO_H
#define VIDEO_H

void screen_clear( );
void screen_setCursor( short x, short y );
void screen_newline( );
void screen_tab( );
void screen_printString( char* str );
void screen_printHex( unsigned int );
void screen_printDec( unsigned int );
void screen_scroll( );

#endif