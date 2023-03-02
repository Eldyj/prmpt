# prmpt

simple shell prompt engine in C

## templates

- @pwd
- @cwd
- @spwd

## usage

```bash
prmpt "separator" "fgcolor;bgcolor;text or @prepared-template" "same as thing after separator" "again" "..."
```

```bash
# my prompt:
prmpt "" "blue;black;$USER" "black;green;@spwd"
```
