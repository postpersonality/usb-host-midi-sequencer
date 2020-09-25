# USB Host MIDI Sequencer

(project description tba)

## Device layout

[![Device layout image](docs/wireframe.png)](https://wireframe.cc/Jiip4M)

## Bill of materials

| Material                   | Pieces | Shop Links |
|----------------------------|--------|------------|
| Arduino-compatible MCU     | 1      |            |
| USB Host Shield            | 1      |            |
| WS2812B 16x16 LED matrix   | 1      |            |
| TM1637 4-digit LED display | 1      |            |
| Buttons                    | ?      |            |
| Encoders                   | ?      |            |

## Limitations

- Max 16 tones per pattern
- Max 16 ticks per pattern
- Max 16 ticks for duration

## Memory math

-
- 7 bits for pitch (full MIDI range)
- 16 bits per note
  - 8 bits pattern offset
  - 4 bits for volume (1-32)
  - 4 bits for duration (1-32)

## Data Structures

Considetations
    - Read performance over write performance
    - Small memory footprint / bits packing

Hierarchy
- Sequence (instrument)
  - Pattern
    - Pattern Row (note pitch)
      - Note (volume, duration)

offset case 3*16 + refs
array case 2*16
