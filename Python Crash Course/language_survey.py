from survey_class import AnonymousSurvey

# Define a question, and make a survey.
question = "What was the first language you wrote 'Hello, world!' in?\n"
my_survey = AnonymousSurvey(question)

# Show the question, and store responses to the question
my_survey.show_question()
print("Enter 'q' at any time to quit.\n")
while True:
    response = input("Language: ")
    if response == 'q':
        break
    my_survey.store_response(response)

# Show results
print("\nThanks to the participants!")
my_survey.show_results()