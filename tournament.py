# Simulate a sports tournament

import csv
import sys
from sys import argv
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage(we use argv to say hey we have this teams here so make an tournoment between them)
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # Read teams into memory from file
    with open(argv[1], "r") as team_files:
        team_reader = csv.DictReader(team_files)
        for row in team_reader:
            #team_list = list(team_reader)
            teams.append(row)
            # turn ratings to int(they're string now)
            row['rating'] = int(row['rating'])

    counts = {}
    # Simulate N tournaments and keep track of win counts
    # actually this dict sort team names and how much they have won
    # there's N number of game between teams
    for game in range(N):
        # we want to get tournament winners and than count number of they're winning
        win = simulate_tournament(teams)
        # when there's a repeat in winner names(for example japan won 3 times) ++ the number of winning
        if win in counts:
            counts[win] += 1
            # if that's not true than that team won nothing
        else:
            counts[win] = 0

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

# simulate a game between two tems(each team are dict for themselves)


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

# get a list of teams for input(teams) and simulate a game between them and then give a list of that round winners(winners list)


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners

# this function simulate rond of tournoments between teams and when there's one team, return name of it


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # we want to have matches between the teams(list that is upper from here) so we should have n(len teams) tournements
    for tournament in range(len(teams)):
        # when at least there's more tournament than a power of 2, we should make tournaments and then print the first winner of tournments
        while tournament >= 2:
            return simulate_round(teams)
            # as website said we can return simulate round here
            return simulate_tournaments(teams)
            # at the last tournament, return all of this rounds winner
        else:
            return teams[0]['team']


if __name__ == "__main__":
    main()
