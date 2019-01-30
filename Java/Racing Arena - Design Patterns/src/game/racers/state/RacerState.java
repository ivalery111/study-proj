package game.racers.state;

import utilities.EnumContainer.RacerEvent;

public interface RacerState {
	public void racerStateChanged(RacerEvent event);

}
