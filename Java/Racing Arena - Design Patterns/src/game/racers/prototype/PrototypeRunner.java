package game.racers.prototype;

import game.racers.Racer;
import game.racers.land.Car;

public class PrototypeRunner {

	public static void main(String[] args) {
		
		Racer racer = new Car();

		PrototypeFactory factory = new PrototypeFactory(racer);
		
		Racer racerClone = factory.cloneRacer();
		
		System.out.println(racerClone);
	}

}
