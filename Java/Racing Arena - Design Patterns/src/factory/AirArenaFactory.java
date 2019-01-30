
package factory;

import game.arenas.Arena;
import game.arenas.air.AerialArena;

public class AirArenaFactory implements IArenaFactory {

	@Override
	public Arena createArena() {
		return new AerialArena();
	}

}
