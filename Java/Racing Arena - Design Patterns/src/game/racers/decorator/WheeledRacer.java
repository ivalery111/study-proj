package game.racers.decorator;

import game.racers.IRacer;

public class WheeledRacer extends RacerDecorator{
	
	private String ATTRIBUTENAME = "numOfWheels";
	
	public WheeledRacer(IRacer racer, int num) {
		super(racer);
		super.addAttribute(ATTRIBUTENAME, num);
	}
}
