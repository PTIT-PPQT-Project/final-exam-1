import sys

def solve():
    try:
        # Read the first line for H (height) and W (width)
        try:
            line = sys.stdin.readline().split()
            if not line:
                return
            H = int(line[0])
            W = int(line[1])
        except (ValueError, IndexError):
            return # Handle case where H W line is malformed or empty

        histogram = {}
        pixel_count = H * W

        # Read the next H lines, each with W grayscale values
        count = 0
        for _ in range(H):
            try:
                line = sys.stdin.readline().split()
                if not line:
                    continue

                for val_str in line:
                    if count >= pixel_count:
                        break # Safety break if too many values are read
                    
                    try:
                        val = int(val_str)
                        if 0 <= val <= 255:
                            histogram[val] = histogram.get(val, 0) + 1
                            count += 1
                    except ValueError:
                        continue # Skip non-integer values
            except EOFError:
                break
        
        # Filter for grayscale values that appear at least once and sort them
        # The problem implies we only care about the values that appeared (count >= 1)
        # Since we only add to the histogram if they appear, we just need to sort the keys.
        sorted_grayscale_values = sorted(histogram.keys())
        
        # Output the results
        for gray_level in sorted_grayscale_values:
            count = histogram[gray_level]
            print(f"{gray_level} {count}")

    except Exception as e:
        # Optionally handle other exceptions if necessary, but keep the code clean
        # print(f"An error occurred: {e}", file=sys.stderr)
        pass

if __name__ == "__main__":
    solve()