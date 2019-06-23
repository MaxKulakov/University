import json

answers = list()
flag = 0


def open_json_by_tag(tag):
    questions = open('questions.json', 'r')
    datastore = json.load(questions)
    return datastore[tag]

