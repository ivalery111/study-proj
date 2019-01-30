package game.racers.land;

import java.util.HashMap;

import game.racers.Racer;
import game.racers.Wheeled;
import utilities.EnumContainer.Color;
import utilities.EnumContainer.Engine;

public class Car extends Racer implements ILandRacer {

	private static final String CLASS_NAME = "Car";

	private static final int DEFAULT_WHEELS = 4;
	private static final double DEFAULT_MAX_SPEED = 400;
	private static final double DEFAULT_ACCELERATION = 20;
	private static final Color DEFAULT_color = Color.RED;

	private Engine engine;
	private Wheeled wheeled;

	public Car() {
		this(CLASS_NAME + " #" + lastSerialNumber, DEFAULT_MAX_SPEED, DEFAULT_ACCELERATION, DEFAULT_color,
				DEFAULT_WHEELS);
		map = new HashMap<>();
		map.put("numOfWheels", this.getWheeled().getNumOfWheels());
		map.put("color", this.getColor());
		setIsWheeled(true);
	}

	public Car(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color,
			int numOfWheels) {
		super(name, maxSpeed, acceleration, color);
		this.setWheeled(new Wheeled(numOfWheels));
		this.setEngine(Engine.MOUNTAIN);

		map = new HashMap<>();
		map.put("numOfWheels", this.getWheeled().getNumOfWheels());
		map.put("color", this.getColor());
		setIsWheeled(true);
	}

	@Override
	public String className() {
		return CLASS_NAME;
	}

	@Override
	public String describeSpecific() {
		String s = "";
		s += " numOfWheels: [" + map.get("numOfWheels") + "]";
		s += ", Engine Type: " + this.engine;

		return s;
	}

	public Engine getEngine() {
		return engine;
	}

	public Wheeled getWheeled() {
		return wheeled;
	}

	public void setEngine(Engine engine) {
		this.engine = engine;
	}

	public void setWheeled(Wheeled wheeled) {
		this.wheeled = wheeled;
	}

	@Override
	public void addAttribute(String nameAttr, Object target) {

		if (map == null) {
			map.put(nameAttr, target);
		} else {
			map.put(nameAttr, map.get(nameAttr) + ", " + target);
		}

	}

	@Override
	public Object copy() {
		Car copy = new Car(this.getName(),this.getMaxSpeed(),this.getAcceleration(),this.getColor(),this.getWheeled().getNumOfWheels());
		return copy;
	}

}












