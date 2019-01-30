package game.racers.naval;

import java.util.HashMap;

import game.racers.Racer;
import game.racers.air.Airplane;
import utilities.EnumContainer;
import utilities.EnumContainer.BoatType;
import utilities.EnumContainer.Color;
import utilities.EnumContainer.Team;

public class RowBoat extends Racer implements INavalRacer {
	private static final String CLASS_NAME = "RowBoat";

	private static final double DEFAULT_MAX_SPEED = 75;
	private static final double DEFAULT_ACCELERATION = 10;
	private static final Color DEFAULT_color = Color.RED;

	private EnumContainer.BoatType type;
	private EnumContainer.Team team;

	public RowBoat() {
		this(CLASS_NAME + " #" + lastSerialNumber, DEFAULT_MAX_SPEED, DEFAULT_ACCELERATION, DEFAULT_color);
		map = new HashMap<>();
		map.put("color", this.getColor());
		setIsWheeled(false);
	}

	public RowBoat(String name, double maxSpeed, double acceleration, utilities.EnumContainer.Color color) {
		super(name, maxSpeed, acceleration, color);
		this.setType(BoatType.SKULLING);
		this.setTeam(Team.SINGLE);
		map = new HashMap<>();
		map.put("color", this.getColor());
		setIsWheeled(false);
	}

	public EnumContainer.BoatType getType() {
		return type;
	}

	public void setType(EnumContainer.BoatType type) {
		this.type = type;
	}

	public EnumContainer.Team getTeam() {
		return team;
	}

	public void setTeam(EnumContainer.Team team) {
		this.team = team;
	}

	@Override
	public String className() {
		return CLASS_NAME;
	}

	@Override
	public String describeSpecific() {
		String s = "";
		s += ", Type: " + this.type;
		s += ", Team: " + this.team;
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
		RowBoat copy = new RowBoat(this.getName(),this.getMaxSpeed(),this.getAcceleration(),this.getColor());

		return copy;
	}

}
