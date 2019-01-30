
package factory;

import game.arenas.Arena;

public class ArenaFactory {
	
	public static Arena createArenaByScpeciality(String speciality) {
		
		if(speciality.equalsIgnoreCase("Air")) {
			return new AirArenaFactory().createArena();
		}
		else if(speciality.equalsIgnoreCase("Land")) {
			return new LandArenaFactory().createArena();
		}
		else if(speciality.equalsIgnoreCase("Naval")) {
			return new NavalArenaFactory().createArena();
		}
		else {
			throw new RuntimeException(speciality + " is unknown speciality");
		}
	}

}
