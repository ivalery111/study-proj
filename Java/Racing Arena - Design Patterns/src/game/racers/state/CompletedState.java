package game.racers.state;

import utilities.EnumContainer.RacerEvent;

public class CompletedState implements RacerState{

	@Override
	public void racerStateChanged(RacerEvent event) {
		System.out.println("[Completed] - need to say to arena");

	}
	
}
