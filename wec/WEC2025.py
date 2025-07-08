import re
from typing import List
import json


DAY_MAP = {"Mo": 0, "Tu": 1, "We": 2, "Th": 3, "Fr": 4, "Sa": 5, "Su": 6}


class Time:
    def __init__(self, time: str):
        self.hour = int(time.split(':')[0])
        self.minute = int(time.split(':')[1])
    
    def __lt__(self, other):
        if isinstance(other, Time):
            return (self.hour, self.minute) < (other.hour, other.minute)
        raise TypeError("Unsupported type for comparison")
    
    def __eq__(self, value: object) -> bool:
        if isinstance(value, Time):
            return (self.hour, self.minute) == (value.hour, value.minute)
        raise TypeError("Unsupported type for equality check")
    
    def __le__(self, other):
        if isinstance(other, Time):
            return (self.hour, self.minute) <= (other.hour, other.minute)
        raise TypeError("Unsupported type for comparison")
    
    def __str__(self):
        return f"{self.hour:02}:{self.minute:02}"
    
    def __sub__(self, other):
        if isinstance(other, Time):
            return (self.hour * 60 + self.minute) - (other.hour * 60 + other.minute)
        raise TypeError("Unsupported type for subtraction")


class Event:
    def __init__(self,
                 event_type:str,
                 event_name:str,
                 start_time:str, end_time:str,
                 location:str, is_on_campus:bool,
                 day:int = -1,
                 school_event_type:str = ""):
        self.event_type = event_type # School, Social, ECs
        self.school_event_type = school_event_type #only for School events
        self.event_name = event_name
        self.start_time = Time(start_time)
        self.end_time = Time(end_time)
        self.location = location
        self.is_on_campus = is_on_campus
        self.day = day

    def get_profit(self):
        if self.event_type == "School":
            return 100
        elif self.event_type == "ECs":
            return 75
        elif self.event_type == "Social":
            return 50
        else:
            assert False

    def __str__(self):
        return (f"{self.event_name} ({self.event_type}) from {self.start_time} to {self.end_time} "
                f"at {self.location}, day {self.day}")

def parse_input_file(file_path: str) -> List[Event]:
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = [line.strip() for line in f if line.strip()]

    i = 0
    events = []

    while i < len(lines):
        header = re.match(r"\((\w+),\s*(\d+)\)", lines[i])
        if not header:
            i += 1
            continue
        section_type, count = header.groups()
        count = int(count)
        i += 1

        for _ in range(count):
            raw = lines[i].strip("()").replace("–", "-")  # Normalize long dash
            parts = [p.strip() for p in raw.split(",")]

            if section_type == "SOCIAL":
                name, location, on_campus, time_range = parts
                start, end = time_range.split("-")
                event = Event("Social", name, start, end, location, on_campus.lower() == "true")
                events.append(event)

            elif section_type == "SCHOOL":
                name, typ, location, time_day = parts
                match = re.match(r"(\d{1,2}:\d{2})-(\d{1,2}:\d{2})\s*([A-Za-z]{2})?", time_day)
                if match:
                    start, end, day = match.groups()
                    day_index = DAY_MAP.get(day, -1)
                    event = Event("School", name, start, end, location, True, day=day_index, school_event_type=typ)
                    events.append(event)

            elif section_type == "ECs":
                typ, location, on_campus, time_range = parts
                start, end = time_range.split("-")
                event = Event("ECs", typ, start, end, location, on_campus.lower() == "true")
                events.append(event)

            i += 1

    return events


def can_come_next(e1: Event, e2: Event) -> bool:
    """
    Check if event e2 can come after event e1 without overlap.
    """
    # return e1.end_time <= e2.start_time
    
    # Same location rule
    if e1.location == e2.location:
        commute = 0
    elif e1.is_on_campus and e2.is_on_campus:
        commute = 15
    elif not e1.is_on_campus and not e2.is_on_campus:
        commute = 25
    else:
        commute = 25
    
    # Calculate end time + commute as (hour, minute)
    end_hour = e1.end_time.hour
    end_minute = e1.end_time.minute + commute
    if end_minute >= 60:
        end_hour += end_minute // 60
        end_minute = end_minute % 60

    # e2 can come after e1 if e1 ends + commute <= e2 starts
    return (end_hour, end_minute) <= (e2.start_time.hour, e2.start_time.minute)


def maxProfit(events: list[Event]):
    n = len(events)

    # Sort jobs by start time (can also sort by end time for easier binary search)
    events = list(sorted(events, key=lambda x: x.start_time))
    
    # dp[i] = (max_profit_from_i, [indices of jobs taken from i])
    dp = [(0, []) for _ in range(n)]
    
    res = 0
    best_subset = []
    
    for i in range(n - 1, -1, -1):
        profit_with = events[i].get_profit()
        next_idx = -1
        # Find next non-overlapping job
        for j in range(i + 1, n):
            if can_come_next(events[i], events[j]):
                next_idx = j
                break
        # If taking this job, add profit from next compatible job
        if next_idx != -1:
            profit_with += dp[next_idx][0]
            subset_with = [i] + dp[next_idx][1]
        else:
            subset_with = [i]
        # If skipping this job, take dp[i+1]
        if i + 1 < n:
            profit_without, subset_without = dp[i + 1]
        else:
            profit_without, subset_without = 0, []
        # Choose better option
        if profit_with > profit_without:
            dp[i] = (profit_with, subset_with)
        else:
            dp[i] = (profit_without, subset_without)
        # Track overall best
        if dp[i][0] >= res:
            res = dp[i][0]
            best_subset = dp[i][1]

    # Return max profit and the subset of jobs (as actual Event instances)
    return res, [events[i] for i in best_subset]


def solve(events: list[Event]) -> list[list[Event]]:
    school = [[] for _ in range(7)]
    other = [[] for _ in range(7)]

    # School, Social, ECs type of events
    for i in range(7):
        for event in events:
            if event.event_type == "School":
                assert event.day != -1, "school events must have a day assigned"
                if event.day == i:
                    school[i].append(event)
            else:
                # Social or ECs events can be on any day
                other[i].append(event)
    
    # The set of days to consider
    days_remaining = set(range(7))
    schedule = [[] for _ in range(7)]

    while len(days_remaining) > 1:
        # For each day, calculate the max profit
        # and the events selected for that day
        # (profit, day_index, day_events, unselected_events, unselected_school)
        scores = []

        for i in days_remaining:
            profit, day_events = maxProfit(school[i] + other[i])
            all_events = set(school[i] + other[i])
            selected_events = set(day_events)
            unselected_events = all_events - selected_events
            unselected_school = set()
            for unselected in unselected_events:
                # If any school event is unselected, this is suboptimal
                if unselected.event_type == "School":
                    unselected_school.add(unselected)
            # Calculate the score for each day
            score = profit - len(unselected_school) * 100
            scores.append((score, i, day_events, unselected_events, unselected_school))
        
        # Sort scores by score value, descending
        scores.sort(reverse=True, key=lambda x: x[0])
        # Return the best day and its score
        best_score, best_day, day_events, unselected_events, unselected_school = scores[0]

        # Remove the best day from the remaining days
        days_remaining.remove(best_day)

        # Add the best day's events to the schedule
        schedule[best_day] = day_events
        
        # Update the events for remaining days
        for i in range(7):
            if i == best_day:
                continue
            # Remove the events of the best day from the other days
            other[i] = list(unselected_events - unselected_school)
        
    return schedule


def solve_one_sleep(sch1, sch2) -> tuple:
    """
    Given two schedules, find the best time to sleep.
    This function assumes that sch1 and sch2 are lists of events for two different days.
    """

    start_hour = 22
    start_minute = 1
    end_hour = 6
    end_minute = 1

    penalty = list()

    # Check minute by minute for the best sleep time
    for mn in range(119):
        # Create a sleep event for the current minute
        sleep_start = Time(f"{start_hour + mn // 60:02}:{start_minute + mn % 60:02}")
        sleep_end = Time(f"{end_hour + mn // 60:02}:{end_minute + mn % 60:02}")

        # Check the penalty for this sleep event
        to_remove_first = []
        to_remove_second = []
        penal = 0
        for event in sch1:
            if event.start_time >= sleep_start or event.end_time >= sleep_start:
                penal += event.get_profit()
                to_remove_first.append(event)
        for event in sch2:
            if event.start_time <= sleep_end or event.end_time <= sleep_end:
                penal += event.get_profit()
                to_remove_second.append(event)
        
        penalty.append((penal, mn, to_remove_first, to_remove_second))
    
    penalty = list(sorted(penalty, key=lambda x: x[0]))  # Sort by penalty, ascending
    penal, mn, to_remove_first, to_remove_second = penalty[0]

    first_sleep = Event(
        event_type="Sleep",
        event_name="Sleep Night",
        start_time=f"{start_hour + mn // 60:02}:{start_minute + mn % 60:02}",
        end_time=f"{24}:{00}",
        location="Bed",
        is_on_campus=False
    )
    second_sleep = Event(
        event_type="Sleep",
        event_name="Sleep Morning",
        start_time=f"{00}:{00}",
        end_time=f"{end_hour + mn // 60:02}:{end_minute + mn % 60:02}",
        location="Bed",
        is_on_campus=False
    )
    return first_sleep, second_sleep, to_remove_first, to_remove_second


def when_to_sleep(schedule: list[list[Event]]) -> list[list[Event]]:
    for i in range(7):
        first_day = i
        second_day = (i + 1) % 7
        sch1 = schedule[first_day]
        sch2 = schedule[second_day]
        e1, e2, to_remove_first, to_remove_second = solve_one_sleep(sch1, sch2)
        # Remove the events that are conflicting with the sleep time
        for event in to_remove_first:
            sch1.remove(event)
        for event in to_remove_second:
            sch2.remove(event)
        # Add the sleep events to the schedule
        sch1.append(e1)
        sch2.insert(0, e2)

    return schedule


def evaluate_schedule(schedule, all_events: list[Event]) -> float:
    """
    Evaluates a schedule and returns its composite score.
    This is the FITNESS FUNCTION for the GA.
    
    NOTE: The full implementation of this function is complex and would be
    placed in another file (e.g., main.py). It must calculate the score
    based on all rules in the problem description.
    """
    school_score, ec_score, social_score = 10.0, 10.0, 10.0
    
    scheduled_events = [event for day in schedule for event in day]
    scheduled_event_names = {e.event_name for e in scheduled_events}
    study_hours = sum((e.end_time - e.start_time) / 60 for e in scheduled_events if e.school_event_type == "study")
    if study_hours < 5:
        school_score -= 3
    school_score += study_hours * 0.5

    for event in all_events:
        if event.event_type == "School" and event.event_name != "Study":
            is_scheduled = event.event_name in scheduled_event_names
            if event.school_event_type == "lecture" or event.school_event_type == "class":
                school_score += 2 if is_scheduled else -2 
            elif event.school_event_type == "lab":
                school_score += 1.5 if is_scheduled else -1.5
            elif event.school_event_type == "tutorial":
                school_score += 0.75 if is_scheduled else -0.75
    
    ec_score += sum(1 for e in scheduled_events if e.event_type == "ECs") 
    social_score += sum(1 for e in scheduled_events if e.event_type == "Social")

    composite_score = school_score + 0.75 * ec_score + 0.5 * social_score

    return composite_score


days_rev = {
    0: "Monday",
    1: "Tuesday",
    2: "Wednesday",
    3: "Thursday",
    4: "Friday",
    5: "Saturday",
    6: "Sunday"
}


def output(schedule, score, dir="output_dp.json"):
    dictionary = {"Monday":{}, "Tuesday": {}, "Wednesday": {}, "Thursday": {}, "Friday": {}, "Saturday": {}, "Sunday": {}}

    for i in range(7):
        key = days_rev[i]
        for e in schedule[i]:
            dictionary[key][e.event_name] = [str(e.start_time), str(e.end_time)]
    print(" >>>> score <<<< ", score)
    dictionary["score"]=score

    with open(dir, "w") as outfile:
        json.dump(dictionary, outfile, indent=4)


########################################################################################################################
# Test
########################################################################################################################

import os
filename = input("Enter the path to the JSON file: ").strip()

if not os.path.isfile(filename):
    print(f"File '{filename}' does not exist.")
    exit(1)
else:
    pass
input_file = filename  # Path to your input file
events = parse_input_file(input_file)
schedule = when_to_sleep(solve(events))
for i, day_events in enumerate(schedule):
    day_name = ["Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"][i]
output(schedule, evaluate_schedule(schedule, events), "output_dp.json")
