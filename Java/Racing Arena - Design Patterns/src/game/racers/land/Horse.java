package game.racers.land;

import java.util.HashMap;

import game.racers.Racer;
import game.racers.air.Helicopter;
import utilities.EnumContainer;
import utilities.EnumContainer.Breed;
import utilities.EnumContainer.Color;

public class Horse extends Racer implements ILandRacer {

	private static final String CLASS_NAME = "Horse";

	private static final double DEFAULT_MAX_SPEED = 50;
	private static final double DEFAULT_ACCELERATION = 3;
	private static final Color DEFAULT_color = Color.BLACK;

	private EnumContainer.Breed breed;

	public Horse() {
		this(CLASS_NAME + " #" + lastSerialNumber, DEFAULT_MAX_SPEED, DEFAULT_ACCELERATION, DEFAULT_color);
		map = new HashMap<>();
		// map.put("numOfWheels", 0);
		map.put("color", this.getColor());
		setIsWheeled(false);
	}

	public Horse(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color) {
		super(name, maxSpeed, acceleration, color);
		this.setBreed(Breed.THOROUGHBRED);
		map = new HashMap<>();
		map.put("color", this.getColor());
		setIsWheeled(false);
	}

	@Override
	public String className() {
		return CLASS_NAME;
	}

	@Override
	public String describeSpecific() {
		String s = "";
		s += ", Breed: " + this.breed;
		s += " numOfWheels: [" + map.get("numOfWheels") + "]";
		return s;
	}

	public EnumContainer.Breed getBreed() {
		return breed;
	}

	public void setBreed(EnumContainer.Breed breed) {
		this.breed = breed;
	}

	@Override
	public void addAttribute(String nameAttr, Object target) {
		if (nameAttr.equalsIgnoreCase("numOfWheels")) {
			this.setIsWheeled(true);
		}
		if (map == null) {
			map.put(nameAttr, target);
		} else {
			map.put(nameAttr, map.get(nameAttr) + ", " + target);
		}

	}

	@Override
	public Object copy() {
		Horse copy = new Horse(this.getName(),this.getMaxSpeed(),this.getAcceleration(),this.getColor());
		return copy;
	}

}
