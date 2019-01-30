
package game.builder;

import java.util.ArrayList;

import factory.ArenaFactory;
import factory.IArenaFactory;
import game.arenas.Arena;
import game.racers.Racer;

public class Race {

	private Arena arena;
	//private ArrayList<Racer> racers;


	public Arena getArena() {
		return arena;
	}

	public void setArena(Arena arena) {
		this.arena = arena;
	}

//	public ArrayList<Racer> getRacers() {
//		return racers;
//	}

//	public void setRacers(ArrayList<Racer> racers) {
//		this.racers = racers;
//	}

	@Override
	public String toString() {
		return "Race [arena=" + arena + "]";
	}

}
