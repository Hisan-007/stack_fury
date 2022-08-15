file = open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\new_new_answers_page.txt", "r", encoding="utf-8")
list_of_elements = [x.split(' ') for x in file.read().split('\n')]
list_of_elements = [ x for x in list_of_elements if len(x)>1]
only_kw = [x[0] for x in list_of_elements]
only_kw = list(set(only_kw))
only_kw.sort()
items = [ [x,[]] for x in only_kw]

def findIndices(word):
        list = []
        for i in range(len(list_of_elements)):
                if(list_of_elements[i][0]==word):
                        #print("beep", i)
                        list.append(list_of_elements[i][1])
        return list;
print(len(only_kw))
for i in range(len(only_kw)):
        print(i)
        temp_url_list = findIndices(only_kw[i])
        for j in temp_url_list:
                items[i][1].append(j)
