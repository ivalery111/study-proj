package game.racers.decorator;

import game.racers.IRacer;

public class RacerDecorator implements IRacer {

	protected IRacer decoratedRacer;

	public RacerDecorator(IRacer racer) {

		decoratedRacer = racer;

	}

	@Override
	public void addAttribute(String nameAttr, Object targer) {
		
		decoratedRacer.addAttribute(nameAttr, targer);

	}

	@Override
	public void introduce() {
		decoratedRacer.introduce();

	}

}
