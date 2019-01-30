
package game.arenas.exceptions;

@SuppressWarnings("serial")
public class RacerLimitException extends Exception {
	
	public RacerLimitException(int max_racers, int racerNumber) {
		//super(msg);
		super("Arena is full! (" + max_racers + " active racers exist). racer #" + racerNumber + " was not added");
	}
	public RacerLimitException(String msg) {
		super(msg);
	}
	
	
	
	
	

}
