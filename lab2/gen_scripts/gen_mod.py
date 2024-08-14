import random
import string

def generate_random_string(length):
    """Generates a random string of fixed length."""
    return ''.join(random.choices(string.ascii_lowercase, k=length))

def generate_input_file(filename, num_strings, order='random'):
    """Generates an input file with strings in the specified order."""
    with open(filename, 'w') as file:
        strings = [generate_random_string(10) for _ in range(num_strings)]

        if order == 'ascending':
            strings.sort()
        elif order == 'descending':
            strings.sort(reverse=True)
        elif order == 'random':
            random.shuffle(strings)
        else:
            raise ValueError("Order must be 'ascending', 'descending', or 'random'")

        for s in strings:
            file.write(s + '\n')

def main():
    num_strings = int(input("Enter the number of inputs"))  # Number of strings to generate

    # Generate files in different orders
    generate_input_file(f'/Users/yeyatiprasher/College_stuff/DAA/lab2/ascending{num_strings}.txt', num_strings, 'ascending')
    generate_input_file(f'/Users/yeyatiprasher/College_stuff/DAA/lab2/descending{num_strings}.txt', num_strings, 'descending')
    generate_input_file(f'/Users/yeyatiprasher/College_stuff/DAA/lab2/random{num_strings}.txt', num_strings, 'random')

    print("Files generated: ascending.txt, descending.txt, random.txt")

if __name__ == "__main__":
    main()
