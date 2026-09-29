# devops-cs202

Team:
1. 24110274 - Pranjal Goyal
2. 24110376 - Ujas Devang Shah

## Project Workflow
  
1. Created a new folder, ran `git init`
2. Started with a simple command-line calculator in `main.cpp` supporting `+`, `-`, `*`, and `/`. This was done in the `master` branch.
3. Checked out a new branch `maths`, from `master`
4. Separated the arithmetic functions into `mathfuncs.cpp`, with declarations in `mathfuncs.h`.
5. Added assertions in `main.cpp` to test every arithmetic function.
6. Fetched partner's `random` branch, created a local branch, rebased it onto `master`, resolved the `main.cpp` conflict by keeping both feature sets, and fast-forwarded `master`.
7. Added random-function tests and runtime output while preserving the calculator.
8. Created a local `build-system` branch for the Makefile and `.gitignore`, then merged it into `master` with a fast-forward merge.
9. Added this README.md

## Sharing the Repo Link to Professor
### Identifying Professor's IP address
1. First, identify the subnet mask of the shared Wi-Fi:

```
❯ ifconfig en0 | grep "inet "
	inet 10.240.4.231 netmask 0xffffe000 broadcast 10.240.31.255
```

| Property         | Value                          |
| ---------------- | ------------------------------ |
| Your IP          | `10.240.4.231`                 |
| Subnet mask      | `255.255.224.0`                |
| Network address  | `10.240.0.0`                   |
| Broadcast        | `10.240.31.255`                |
| Usable IPs       | `10.240.0.1` – `10.240.31.254` |
| Total usable IPs | 8,190                          |
Leading 1 bits = 8 + 8 + 3 = 19
So,  **Network address: 10.240.0.0/19**

2.  The professor said they have opened port **6005**, so we can search across the subnet using `nmap`
```
❯ nmap -sT -p 6005 --open 10.240.0.0/19
Starting Nmap 7.991 ( https://nmap.org ) at 2026-09-29 11:21 +0530
```
3. But we noticed this was taking a very long time. So I interrupted this and added a few more flags:
```
❯ nmap -n -Pn -sT -p 6005 --open --max-retries 1 --host-timeout 3s 10.240.0.0/19
```
- `-n`: Skip DNS resolution.
- `-Pn`: Skip host discovery.
- `--max-retries 1`: Limit retransmissions.
- `--host-timeout 3s`: Stop scanning an unresponsive host after three seconds.
This also took some time (there are >8000 IPs to search through!), but eventually we were able to identify the IP: 

$$
\boxed{10.240.14.118}
$$

4. Once we got the IP, all we had to do is send the repository link using Netcat (`nc`) :
```
❯ echo "https://github.com/PranjalGoyal06/devops-cs202/" | nc 10.240.14.118 6005
(base) ~ took 19s
```

Done!