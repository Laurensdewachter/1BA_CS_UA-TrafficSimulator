### TrafficSimulation

- Attributes:
  - `std::vector<Street*> fStreets`


- `EParserSucces parseInputFile(const std::string &filename, std::ostream &errStream)`
  - Parses a given xml-file using the help of the ElementParser. Other types of files are not supported and result
    in an error.
- `void writeOn(std::ostream &outStream) const`
  - Writes the content of the object to the given stream
- `void visualize(std::ostream &onstream = std::cout) const`
  - Visualizes the content of the object on the given stream when it is pipelined to the visualizer.
- `void simulate()`
  - Moves one time-unit forward in the simulation.
  
### ElementParser

- Attributes:
  - `std::vector<Street*> fStreets`
  - `std::vector<TrafficLight*> fTrafficLights`
  - `std::vector<Vehicle*> fVehicles`
  - `std::vector<VehicleGenerator*> fVehicleGenerators`


- `EParserSucces parseFile(const std::string &filename, std::ostream &errStream)`
  - Splits a xml-file into the different types of objects and sends them to their corresponding parser.
    All created objects are stored in vectors.
- `std::vector<Street*> getStreets() const`
  - Returns the vector that contains all created streets.
- `std::vector<TrafficLight*> getTrafficLights() const`
  - Returns the vector that contains all created traffic lights.
- `std::vector<Vehicle*> getVehicles() const`
  - Returns the vector that contains all created vehicles.
- `std::vector<VehicleGenerator*> getVehicleGenerators() const`
  - Returns the vector that contains all created vehicle generators.

### StreetParser

- Attributes:
  - `Street* fStreet`
  

- `bool parseStreet(TiXmlElement* BAAN, std::ostream &errStream)`
  - Parses a street element from a xml-file and creates the corresponding street. Returns true when the street was
    correctly parsed, else false.
- `Street* getStreet() const`
  - Returns the created street if it exists.

### TrafficLightParser

- Attributes:
  - `TrafficLight* fTrafficLight`


- `bool parseTrafficLight(TiXmlElement* VERKEERSLICHT, std::ostream &errStream)`
  - Parses a traffic light element from a xml-file and creates the corresponding traffic light. Returns true when the
    traffic light was correctly parsed, else false.
- `TrafficLight* getTrafficLight() const`
  - Returns the created traffic light if it exists.

### VehicleGeneratorParser

- Attributes:
  - `VehicleGenerator* fVehicleGenerator`


- `bool parseVehicleGenerator(TiXmlElement* VOERTUIGGENERATOR, std::ostream &errStream)`
  - Parses a vehicle generator element from a xml-file and creates the corresponding vehicle generator. Returns true
    when the vehicle generator was correctly parsed, else false.
- `VehicleGenerator* getVehicleGenerator() const`
  - Returns the created vehicle generator if it exists.

### VehicleParser
- Attributes:
  - `Vehicle* fVehicle`


- `bool parseVehicle(TiXmlElement* VOERTUIG, std::ostream &errStream)`
  - Parses a vehicle element from a xml-file and creates the corresponding vehicle. Returns true when the vehicle
    was correctly parsed, else false.
- `Vehicle *getVehicle() const`
  - Returns the created vehicle if it exists.

### Street
- Attributes:
  - `std::string fName`
  - `int fLength`
  - `std::vector<TrafficLight*> fTrafficLights`
  - `std::vector<Vehicle*> fVehicles`
  - `VehicleGenerator* fVehicleGenerator`


- `void setName(const std::string &n)`
  - Sets fName to n.
- `void setLength(int l)`
  - Sets fLength to l.
- `void addTrafficLight(TrafficLight* t)`
  - Adds t to the back of fTrafficLights.
- `void addVehicle(Vehicle* v)`
  - Adds v to the back of fVehicles.
- `void setVehicleGenerator(VehicleGenerator* vg)`
  - Sets fVehicleGenerator to vg.
- `void removeVehicle()`
  - Deletes the vehicle that is the farthest on the street.
- `const std::string &getName() const`
  - Returns fName.
- `int getLength() const`
  - Returns fLength.
- `std::vector<TrafficLight*> getTrafficLights() const`
  - Returns fTrafficLights.
- `std::vector<Vehicle*> getVehicles() const`
  - Returns fVehicles.
- `bool hasVehicleGenerator() const`
  - Returns true if fVehicleGenerator is not NULL, else false.
- `void driveVehicles()`
  - Drives all vehicles on the street
- `void simTrafficLights(double &fTime)`
  - Simulates the traffic lights on the street.
- `void sortVehicles()`
  - Sorts the vehicles on the street by their position (farthest first).

### TrafficLight

- Attributes:
  - `std::string fStreet`
  - `int fPosition`
  - `int fCycle`
  - `bool fIsGreen`
  - `double fLastUpdateTime`


- `void setStreet(const std::string &s)`
  - set fStreet to s.
- `void setPosition(int p)`
  - set fPosition to p.
- `void setCycle(int c)`
  - set fCycle to c.
- `void setLastUpdateTime(double u)`
  - set fLastUpdateTime to u.
- `const std::string &getStreet() const`
  - Returns fStreet.
- `int getPosition() const`
  - Returns fPosition.
- `int getCycle() const`
  - Returns fCycle.
- `bool isGreen() const`
  - Returns fIsGreen.
- `double getLastUpdateTime() const`
  - Returns fLastUpdateTime.
- `void changeLight()`
  - Changes the light.

### Vehicle

- Attributes:
  - `std::string fStreet`
  - `double fPosition`
  - `double fSpeed = 0`
  - `double fAcceleration = 0`
  - `double fMaxSpeed = gMaxSpeed`


- `void setStreet(const std::string &s)`
  - set fStreet to s.
- `void setPosition(int p)`
  - set fPosition to p.
- `void setMaxSpeed(double m)`
  - set fMaxSpeed to m.
- `const std::string &getStreet() const`
  - Returns fStreet.
- `double getPosition() const`
  - Returns fPosition.
- `double getSpeed() const`
  - Returns fSpeed.
- `void drive(Vehicle* vehicleInFront = NULL)`
  - Calculates the position, speed and acceleration of the vehicle after a movement.
- `void brake()`
  - Brakes the vehicle.
- `void stop()`
  - Stops the vehicle.

### VehicleGenerator

- Attributes:
  - `std::string fStreet`
  - `int fFrequency`


- `void setStreet(const std::string &s)`
  - set fStreet to s.
- `void setFrequency(int f)`
  - set fFrequency to f.
- `const std::string &getStreet() const`
  - Returns fStreet.
- `int getFrequency() const`
  - Returns fFrequency.