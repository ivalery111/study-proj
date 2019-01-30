package game.racers;

import java.util.HashMap;
import java.util.Observable;
import game.racers.prototype.Copyable;
import game.arenas.Arena;
import game.racers.state.ActiveState;
import game.racers.state.BrokenState;
import game.racers.state.CompletedState;
import game.racers.state.DisabledState;
import game.racers.state.RacerState;
import utilities.EnumContainer;
import utilities.Fate;
import utilities.Mishap;
import utilities.Point;

public abstract class Racer extends Observable implements Runnable, IRacer, Copyable {

	protected static int lastSerialNumber = 1;
	private boolean isWheeled = false;

	// Field for decoration's hash table
	protected HashMap<String, Object> map;

	protected RacerState racerState;

	public void setRacerState(RacerState racerState) {
		this.racerState = racerState;
	}
	private RacerState getRacerState() {
		return racerState;
	}

	public void racerStateChanged() {
		this.notifyObservers(racerState);

	}

	public static int getLastSerialNumber() {
		return lastSerialNumber++;
	}

	private int serialNumber; // Each racer has an unique number, assigned by arena in addRacer() method
	private String name;
	private Point currentLocation;
	private Point finish;
	private double maxSpeed;
	private double acceleration;
	private double currentSpeed;
	private double failureProbability; // Chance to break down
	private EnumContainer.Color color; // (RED,GREEN,BLUE,BLACK,YELLOW)
	private Mishap mishap;
	private double arenaFriction;
	private Arena arena;

	/**
	 * @param name
	 * @param maxSpeed
	 * @param acceleration
	 * @param color
	 */
	public Racer(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color) {
		this.setSerialNumber(Racer.getLastSerialNumber());
		this.setName(name);
		this.setMaxSpeed(maxSpeed);
		this.setAcceleration(acceleration);
		this.setColor(color);
		// DEV init here instead of set method
		this.setFailureProbability(0.2);

		racerState = new ActiveState();

	}

	public abstract String className();

	public String describeRacer() {
		String s = "";
		s += "name: " + this.name + ", ";

		// DEV print location
		s += " @" + this.currentLocation + ", ";

		s += "SerialNumber: " + this.serialNumber + ", ";
		s += "maxSpeed: " + this.maxSpeed + ", ";
		s += "acceleration: " + this.acceleration + ", ";

		s += " color: [" + map.get("color") + "]";

		// s += "color: " + this.color + ", ";
		// s = s.substring(0, s.length() - 2);
		s += this.describeSpecific();
		return s;
	}

	public abstract String describeSpecific();

	public double getAcceleration() {
		return acceleration;
	}

	public Arena getArena() {
		return arena;
	}

	public double getArenaFriction() {
		return arenaFriction;
	}

	public EnumContainer.Color getColor() {
		return color;
	}

	public Point getCurrentLocation() {
		return currentLocation;
	}

	public double getCurrentSpeed() {
		return currentSpeed;
	}

	public double getFailureProbability() {
		return failureProbability;
	}

	public Point getFinish() {
		return finish;
	}

	public Point getLocation() {
		return this.currentLocation;
	}

	public double getMaxSpeed() {
		return maxSpeed;
	}

	public Mishap getMishap() {
		return mishap;
	}

	public String getName() {
		return name;
	}

	public int getSerialNumber() {
		return serialNumber;
	}

	private boolean hasMishap() {
		if (this.mishap != null && this.mishap.getTurnsToFix() == 0) {
			this.setMishap(null);
			this.setChanged();
			
			setRacerState(new ActiveState());
			racerStateChanged();
			this.notifyObservers(new ActiveState());
			
//			this.notifyObservers(RacerEvent.REPAIRED);
		}
		return this.mishap != null;
	}

	public void initRace(Arena arena, Point start, Point finish, double friction) {
		this.setArena(arena);
		this.setCurrentLocation(new Point(start));
		this.setFinish(new Point(finish));
		this.setArenaFriction(friction);
	}

	public void introduce() {
		// Prints a line, obtained from describeRacer(), with its type
		System.out.println("[" + this.className() + "] " + this.describeRacer());
	}

	private boolean isDisabled() {
		if (this.mishap != null) {
			return this.mishap.isFixable() == false;
		}
		return false;
	}

	public void move() {
		double reductionFactor = 1;
		if (!(this.hasMishap()) && Fate.breakDown(this.failureProbability)) {
			this.mishap = Fate.generateMishap();
			this.setChanged();
			System.out.println(this.name + " Has a new mishap! (" + this.mishap + ")");
			if (this.isDisabled()) {
				// racerState = new DisabledState();
				// racerState.racerStateChanged();
				
				setRacerState(new DisabledState());
				racerStateChanged();
				this.notifyObservers(getRacerState());
				
//				notifyObservers(RacerEvent.DISABLED);
				return;
			} else {
				// racerState = new BrokenState();
				// racerState.racerStateChanged();
				
				setRacerState(new BrokenState());
				racerStateChanged();
				this.notifyObservers(getRacerState());
				
			}
		}

		if (this.hasMishap()) {
			reductionFactor = mishap.getReductionFactor();
			this.mishap.nextTurn();
		}

		if (this.currentSpeed < this.maxSpeed) {
			this.setCurrentSpeed(this.currentSpeed + this.acceleration * this.arenaFriction);
		}

		double newX = (this.currentLocation.getX() + this.currentSpeed) * reductionFactor;
		Point newLocation = new Point(newX, this.currentLocation.getY());
		this.setCurrentLocation(newLocation);
	}

	private boolean raceInPrograss() {
		return this.currentLocation.getX() < this.finish.getX();
	}

	@Override
	public void run() {
		while (this.raceInPrograss() && this.isDisabled() == false) {
			this.move();
		}
		if (this.isDisabled())
			return;
		setChanged();
		
		setRacerState(new CompletedState());
		racerStateChanged();
		this.notifyObservers(getRacerState());
		
//		this.notifyObservers(RacerEvent.FINISHED);
	}

	public void setAcceleration(double acceleration) {
		this.acceleration = acceleration;
	}

	public void setArena(Arena arena) {
		this.arena = arena;
	}

	private void setArenaFriction(double friction) {
		this.arenaFriction = friction;
	}

	public void setColor(EnumContainer.Color color) {
		this.color = color;
	}

	public void setCurrentLocation(Point currentLocation) {
		if (this.finish != null && currentLocation.getX() > finish.getX()) {
			currentLocation.setX(finish.getX());
		}
		this.currentLocation = currentLocation;
	}

	private void setCurrentSpeed(double currentSpeed) {
		if (currentSpeed > this.maxSpeed)
			currentSpeed = this.maxSpeed;
		this.currentSpeed = currentSpeed;
	}

	public void setFailureProbability(double failureProbability) {
		if (failureProbability >= 0 && failureProbability <= 1)
			this.failureProbability = failureProbability;
	}

	public void setFinish(Point finish) {
		this.finish = finish;
	}

	public void setMaxSpeed(double maxSpeed) {
		this.maxSpeed = maxSpeed;
	}

	public void setMishap(Mishap mishap) {
		this.mishap = mishap;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setSerialNumber(int serialNumber) {
		this.serialNumber = serialNumber;
	}

	public boolean isWheeled() {
		return isWheeled;
	}

	public void setIsWheeled(boolean isWheeled) {
		this.isWheeled = isWheeled;
	}
}
