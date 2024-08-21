import networkx as nx


def validate_map_format(input_map):
    for line in input_map.splitlines():
        token = line.split(',')
        try:
            if len(token) != 3:
                raise ValueError('too many inputs in one line')
            start, end, distance = token[0].strip(), token[1].strip(), token[2].strip()
            if not (start.isdecimal() and end.isdecimal()):
                raise ValueError('ID must be integers')
            # 大きさは9999999を最大値にする
            if 7 < len(start) or 7 < len(end):
                raise ValueError('ID is too large')
            if distance.isdecimal():
                if 7 < len(distance):
                    raise ValueError('distance is too large')
            elif float(distance):
                splited = distance.split('.')
                if 7 < len(splited[0]):
                    raise ValueError('integer part of distance is too large')
                elif 2 < len(splited[1]):
                    raise ValueError('fractional part of distance is too large')
        except ValueError as e:
            print(f'Invalid map format: {e}')
            return False
    return True


def main():
    print('hoge')


if __name__ == "__main__":
    main()

