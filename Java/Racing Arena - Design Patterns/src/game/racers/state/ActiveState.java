package game.racers.state;

import utilities.EnumContainer.RacerEvent;

public class ActiveState implements RacerState{

	@Override
	public void racerStateChanged(RacerEvent event) {
		System.out.println("[Active] - need to say to arena");
		
	}
	

}
