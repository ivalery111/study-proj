package game.racers.prototype;

import game.racers.Racer;

public class PrototypeFactory {
	Racer racer;
	
	public void setRacer(Racer racer) {
		this.racer = racer;
	}
	
	public PrototypeFactory(Racer racer) {
		this.racer = racer;
	}
	
	public Racer cloneRacer() {
		return (Racer)racer.copy();
	}
}
