package game.racers.air;

import java.util.HashMap;

import game.racers.Racer;
import game.racers.land.Car;
import utilities.EnumContainer.Color;

public class Helicopter extends Racer implements IAerialRacer {

	private static final String CLASS_NAME = "Helicopter";

	private static final double DEFAULT_MAX_SPEED = 400;
	private static final double DEFAULT_ACCELERATION = 50;
	private static final Color DEFAULT_color = Color.BLUE;

	public Helicopter() {
		this(CLASS_NAME + " #" + lastSerialNumber, DEFAULT_MAX_SPEED, DEFAULT_ACCELERATION, DEFAULT_color);
		this.map = new HashMap<>();
		map.put("color", this.getColor());
		setIsWheeled(false);
	}

	public Helicopter(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color) {
		super(name, maxSpeed, acceleration, color);
		this.map = new HashMap<>();
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
		s += " numOfWheels: [" +map.get("numOfWheels")+"]";
		return s;
	}

	@Override
	public void addAttribute(String nameAttr, Object target) {
		
		if(nameAttr.equalsIgnoreCase("numOfWheels")){
			this.setIsWheeled(true);
		}
		
		if(map == null) {
			map.put(nameAttr, target);
		}
		else {
			map.put(nameAttr, map.get(nameAttr) + ", " + target);
		}
		
	}

	@Override
	public Object copy() {
		Helicopter copy = new Helicopter(this.getName(),this.getMaxSpeed(),this.getAcceleration(),this.getColor());
		return copy;
	}
}
