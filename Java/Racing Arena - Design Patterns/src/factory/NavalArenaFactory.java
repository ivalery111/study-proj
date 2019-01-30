
package factory;

import game.arenas.Arena;
import game.arenas.naval.NavalArena;

public class NavalArenaFactory implements IArenaFactory{

	@Override
	public Arena createArena() {
		return new NavalArena();
	}
	
}
