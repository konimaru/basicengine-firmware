
/* Azip Arduino Zcode Interpreter Program
 * --------------------------------------------------------------------
 * Derived from John D. Holder's Jzip V2.1 source code
 * http://jzip.sourceforge.net/
 * --------------------------------------------------------------------
 */
 
 /*
  * Created by Louis Davis April, 2012
  *
  */

#include "../../ttbasic/basic.h"
#include "azip.h"
#include "ztypes.h"

struct cache_block *cache_blocks;
AZIP *azip;

void azipLoad()
{
  azip = new AZIP;
  cache_blocks = (struct cache_block *)calloc(CACHE_BLOCKS, sizeof(*cache_blocks));
  for (int i = 0; i < CACHE_BLOCKS; ++i) 
    cache_blocks[i].addr = -1;

  azip->open_story( );
  
  // put your setup code here, to run once:
  azip->configure( V1, V8 );

  azip->initialize_screen(  );

  azip->z_restart(  );
}

void azipLoop()
{
  // put your main code here, to run repeatedly:
  azip->interpret( );  
  free(cache_blocks);
}

