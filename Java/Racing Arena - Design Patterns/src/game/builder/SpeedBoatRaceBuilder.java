package game.builder;

import factory.ArenaFactory;
import game.arenas.exceptions.RacerLimitException;
import game.arenas.exceptions.RacerTypeException;
import game.racers.Racer;
import game.racers.naval.SpeedBoat;
import game.racers.prototype.PrototypeFactory;

public class SpeedBoatRaceBuilder extends RaceBuilder{
	

	private int numOfRacers;

	public SpeedBoatRaceBuilder(int numOfRacers) {
		this.numOfRacers = numOfRacers;
	}

	@Override
	void buildArena() {
		race.setArena(ArenaFactory.createArenaByScpeciality("Naval"));
	}

	@Override
	void buildRacers() throws RacerLimitException, RacerTypeException {

		if (numOfRacers > race.getArena().getMaxRacers()) {
			throw new RacerLimitException("Number of racers that you want to add is bigger than maximum racers in arena");

		} else {

			Racer racer = new SpeedBoat(); // Prototype 
			PrototypeFactory factory = new PrototypeFactory(racer);
			race.getArena().addRacer(racer);

			for (int i = 1; i <= numOfRacers; i++) {
				Racer racerClone = factory.cloneRacer();
				race.getArena().addRacer(racerClone);
			}

		}
	}

}
