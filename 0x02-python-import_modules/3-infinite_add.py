#!/usr/bin/python3
if __name__ == "__main__":
    """Print the addition of all arguments."""
    import sys
    result = sum(int(sys.argv[x]) for x in range(1, len(sys.argv)))
    print("{}".format(result))
