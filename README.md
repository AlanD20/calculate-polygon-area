# Calculate Polygon Area

## Downloading the project

here is the commands to work with.

```bash
git clone https://github.com/AlanD20/calculate-polygon-area.git
cd calculate-polygon-area
```

For Windows open `Calculate_Polygon_Area.sln` in Visual Studio.

## How the program works?

The program asks for the file that contains polygon area with the following format

```plaintext
(direction, length), (direction, length), (direction, length),
```

**Directions:**
`E - East`, `N - North`, `W - West`, `S - South`

**Lengths can be float or integer**
`33`, `2.8`, `8.2`

## Example

```plaintext
(S, 25), (E, 7.6), (N, 17.5), (E, 28), (S, 10), (W, 56), (N, 17.5), (E, 20.4), 
```

after the file opened on the program it calculates the total area of the polygon. The result for the example is `580`.

## Contribution

Feel free to add new features to the program as much as you wish. I would love to see a better looking of the program and how you will do it.

## License

[MIT License](LICENSE)
