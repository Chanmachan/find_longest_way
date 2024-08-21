import networkx as nx
import sys


def validate_map_format(input_map):
    validated_data = []
    for line in input_map.splitlines():
        token = line.split(',')
        if len(token) != 3:
            print('Invalid map format: too many inputs in one line')
            return None
        start, end, distance = token[0].strip(), token[1].strip(), token[2].strip()
        if not (start.isdecimal() and end.isdecimal()):
            print('Invalid map format: ID must be integers')
            return None
        if 7 < len(start) or 7 < len(end):
            print('Invalid map format: ID is too large')
            return None
        try:
            dist = float(distance)
            if distance.isdecimal() and 7 < len(distance):
                print('Invalid map format: distance is too large')
                return None
            if not distance.isdecimal() and (7 < len(distance.split('.')[0]) or 2 < len(distance.split('.')[1])):
                print('Invalid map format: part of distance is too large')
                return None
            validated_data.append((int(start), int(end), dist))
        except ValueError:
            print(f'Invalid map format: {distance} is not a float')
            return None
    return validated_data


def load_map(filename):
    try:
        with open(filename, 'r') as f:
            lines = f.read()
        validated_data = validate_map_format(lines)
        if validated_data is None:
            return None
        return validated_data
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        return None


def main():
    if len(sys.argv) != 2:
        print('Error: one input file needed')
        return
    filename = sys.argv[1]
    validated_data = load_map(filename)
    if validated_data is None:
        return
    print(validated_data)


if __name__ == "__main__":
    main()

