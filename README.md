# Isfahan Airport Flight Management

This project is a flight management system for Isfahan Airport, implemented in C++. It allows users to perform various operations related to airplanes, flights, and scheduling.

## Description

The Isfahan Airport Flight Management system is a command-line application that provides the following functionalities:

- Airplanes information: Users can input and store information about different airplanes, including their names and the smallest runways they require.
- Add a flight: Users can add new flights, specifying their type (arrival or exit), flight ID, airplane model, number of passengers, and flight number. The system automatically assigns a suitable runway based on the airplane's requirements.
- Search and cancel a flight: Users can search for flights by flight number or ID and cancel them if needed.
- Sort flights: Flights can be sorted based on their scheduled departure/arrival time.
- Show schedule: Users can view the schedule, including flight numbers, airplane models, scheduled times, number of passengers, IDs, and assigned runways.

## Usage

1. **Airplanes information**: Select option `(1)` from the main menu and follow the prompts to input airplane information.

2. **Add a flight**: Choose option `(2)` from the main menu and provide the required details for the new flight.

3. **Search and cancel a flight**: Select option `(3)` from the main menu and enter the flight number to search for a specific flight. If found, the system will prompt for confirmation to cancel the flight.

4. **Sort flights**: Option `(4)` is currently not implemented.

5. **Show schedule**: Choose option `(5)` from the main menu to display the list of flights, categorized by arrival and exit flights.

## Getting Started

To run the Isfahan Airport Flight Management system locally, follow these steps:

1. Clone this repository to your local machine.
2. Compile the `main.cpp` file using a C++ compiler.
3. Run the compiled executable.

## Contributions

Contributions to this project are welcome! If you find any issues or have suggestions for improvements, please feel free to open an issue or submit a pull request.

