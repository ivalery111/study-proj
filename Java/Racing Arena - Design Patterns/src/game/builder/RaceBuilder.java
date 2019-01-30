package game.builder;

import factory.ArenaFactory;
import game.arenas.exceptions.RacerLimitException;
import game.arenas.exceptions.RacerTypeException;
import game.racers.prototype.PrototypeFactory;

public abstract class RaceBuilder {

	Race race;
	PrototypeFactory factory;
	ArenaFactory arenaFacoty;
	
	void createRace() {
		race = new Race();
	}
	
	abstract void buildArena();
	abstract void buildRacers() throws RacerLimitException, RacerTypeException;
	
	Race getRace() {
		return race;
	}
}
