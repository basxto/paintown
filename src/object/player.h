#ifndef _player_h
#define _player_h

#include "character.h" 
#include "util/keyboard.h"
#include <deque>
#include "util/load_exception.h"

class Animation;
class World;

using namespace std;

class Player: public Character{
public:

	Player( const char * filename ) throw( LoadException );
	Player( const Player & pl ) throw( LoadException );
	Player( const Character & chr ) throw( LoadException );
	
	/* drawing */
	virtual void draw( Bitmap * work, int rel_x );
	
	virtual Object * copy();
	
	virtual void act( vector< Object * > * others, World * world ); 
	
	virtual void takeDamage( ObjectAttack * obj, int x );

	virtual void loseLife( int l = 1 );
	virtual void gainLife( int l = 1 );

	inline const int getLives(){
		return lives;
	}

	/* reset some stuff when the player dies */
	void deathReset();
	
protected:
	void fillKeyCache();
	bool combo( Animation * ani );
	int getKey( int x );

	bool canGrab( Object * enemy );
	void grabEnemy( Object * enemy );
	
protected:

	/* store key presses in a stack with two ends*/
	deque< int > key_cache;
	map< int, bool > last_key;
	int acts;
	Keyboard keyboard;
	int show_life;
	int lives;

	int name_id;

	// int last_key;

};

#endif
