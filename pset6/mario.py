import sys
import cs50

def main():
    
    while True:
        print("enter a non-negative number less than 24: ", end="")
        height = cs50.get_int()
        if height > 0 and height < 24:
            break
    
    for row in range(1, height + 1):
        spaces = height - (row)
        print(" " * spaces, end="")
        print("#" * (row), end="")
        print("  ", end="")
        print("#" * (row))
    
        
if __name__ == "__main__":
    main()
    
    