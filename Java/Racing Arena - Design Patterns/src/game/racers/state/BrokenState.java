package game.racers.state;

import utilities.EnumContainer.RacerEvent;

public class BrokenState implements RacerState{

	@Override
	public void racerStateChanged(RacerEvent event) {
		System.out.println("[Broken] - need to say to arena");
	}

}
