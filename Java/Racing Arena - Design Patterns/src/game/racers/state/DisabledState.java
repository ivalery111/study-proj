package game.racers.state;

import utilities.EnumContainer.RacerEvent;

public class DisabledState implements RacerState{

	@Override
	public void racerStateChanged(RacerEvent event) {
		System.out.println("[Disabled] - need to say to arena");

	}
	
}
