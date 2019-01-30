package game.racers.air;

import java.util.HashMap;

import game.racers.Racer;
import game.racers.Wheeled;
import utilities.EnumContainer.Color;

public class Airplane extends Racer implements IAerialRacer {
	
	private static final String CLASS_NAME = "Airplane";

	private static final int DEFAULT_WHEELS = 3;
	private static final double DEFAULT_MAX_SPEED = 885;
	private static final double DEFAULT_ACCELERATION = 100;
	private static final Color DEFAULT_color = Color.BLACK;
	private Wheeled wheeled;

	public Airplane() {
		this(CLASS_NAME + " #" + lastSerialNumber, DEFAULT_MAX_SPEED, DEFAULT_ACCELERATION, DEFAULT_color,
				DEFAULT_WHEELS);
		this.map = new HashMap<>();
		map.put("numOfWheels", this.getWheeled().getNumOfWheels());
		map.put("color", this.getColor());
		setIsWheeled(true);
	}

	public Airplane(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color,
			int numOfWheels) {
		super(name, maxSpeed, acceleration, color);
		this.setWheeled(new Wheeled(numOfWheels));
		this.map = new HashMap<>();
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
		s += " numOfWheels: [" +map.get("numOfWheels")+"]";
//		s += this.wheeled.describeSpecific();
//		s += ", Engine Type: " + this.engine;
		return s;
//		return this.wheeled.describeSpecific();
	}

	public Wheeled getWheeled() {
		return wheeled;
	}

	public void setWheeled(Wheeled wheeled) {
		this.wheeled = wheeled;
	}

	@Override
	public void addAttribute(String nameAttr, Object target) {

		if(map == null) {
			map.put(nameAttr, target);
		}
		else {
			map.put(nameAttr, map.get(nameAttr) + ", " + target);
		}
		
	}

	@Override
	public Object copy() {
		Airplane copy = new Airplane(this.getName(),this.getMaxSpeed(),this.getAcceleration(),this.getColor(),this.getWheeled().getNumOfWheels());

		return copy;
	}
	
}






