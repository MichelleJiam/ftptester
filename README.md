# ftptester

Unit tester for 42's ft_printf project (per 2019 curriculum).

Current tests:
- Conversion: cspdiuxX%n
- Flags: -0.*'#(space)+
- Modifiers: l ll h hh

Bonus flags are currently mixed in with basic tests. These results are prefixed with "Bonus". 
You can ignore these if you're not doing bonus.

## Installation

Clone the tester into the parent directory of your ft_printf

```bash
git clone https://github.com/MichelleJiam/ftptester.git
```

## Usage

From the ftptester repo, run ```make``` to see options.

Run ```make tests``` to run all tests, except modifer and n. Or ```make (conversion)``` for specific conversions.

Modifier and n bonuses must be tested separately via ```make mod``` & ```make n```.

If changes are made to your source files, please run ```make re``` to recompile.

## License
[MIT](https://choosealicense.com/licenses/mit/)
