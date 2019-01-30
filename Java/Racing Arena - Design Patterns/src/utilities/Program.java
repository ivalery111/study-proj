
package utilities;

import game.builder.Builder;
import game.builder.CarRaceBuilder;
import game.builder.Race;
import game.racers.Racer;
import game.racers.decorator.WheeledRacer;
import game.racers.naval.SpeedBoat;

public class Program {

	/**
	 * @param args
	 * @throws InterruptedException
	 */
	public static void main(String[] args) throws InterruptedException {

		Race mainRace;
		Builder builder = new Builder();

		builder.setBuilder(new CarRaceBuilder(5));

		try {
			// Create race
			mainRace = builder.buildRace();

			// Add to SpeedBoat wheels and try to add to land arena
			Racer s1 = new SpeedBoat();
			new WheeledRacer(s1, 4);

			// add
			mainRace.getArena().addRacer(s1);

			// init race
			mainRace.getArena().initRace();

			// start race
			mainRace.getArena().startRace();

			mainRace.getArena().showResults();

		} catch (Exception e) {
			e.printStackTrace();
		}

	}
}
