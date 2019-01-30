
package game.builder;

import factory.ArenaFactory;
import game.arenas.exceptions.RacerLimitException;
import game.arenas.exceptions.RacerTypeException;

public class Builder {

	RaceBuilder builder;

	public void setBuilder(RaceBuilder builder) {
		this.builder = builder;
	}

	public Race buildRace() throws RacerLimitException, RacerTypeException {

		builder.createRace();
		
		builder.buildArena();
		
		builder.buildRacers();

		Race race = builder.getRace();

		return race;

	}
}
