package game.builder;

import java.util.Scanner;

import game.arenas.exceptions.RacerLimitException;
import game.arenas.exceptions.RacerTypeException;

public class RaceBuilderRunner {

	public static void main(String[] args) {
		Race mainRace;
		Scanner sc = new Scanner(System.in);
		System.out.println("How many racers you need?");
		int numOfRacers = sc.nextInt();

		Builder builder = new Builder();

		builder.setBuilder(new CarRaceBuilder(numOfRacers));

		try {
			mainRace = builder.buildRace();
		} catch (RacerLimitException | RacerTypeException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}

}
