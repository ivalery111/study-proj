
package factory;

import game.arenas.Arena;
import game.arenas.land.LandArena;

public class LandArenaFactory implements IArenaFactory {

	@Override
	public Arena createArena() {
		return new LandArena();
	}
	
}
