#create answers page
from bs4 import BeautifulSoup
import requests
import urllib3

#disable unnecessary warnings to the console
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

all_text=""
#url = "https://stackoverflow.com/questions/59153437/proguard-line-number-
counter = 0
file = open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\stop_words.txt", "r")
stop_words = file.read().split('\n')
for i in range(len(stop_words)):
    stop_words[i] = stop_words[i].replace("'",'')
    
file.close()

file = open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\links_base.txt", "r")
list_of_links = file.read().split('\n')
file.close()


def give_clean_text(text):
            return text.replace('.','').replace(',','').replace(':', '').replace(';','').replace('?','').replace('>','').replace('<','').lower().replace('0','').replace('1','').replace('2','').replace('3','').replace('4','').replace('5','').replace('6','').replace('7','').replace('8','').replace('9','').replace('-','').replace('/','').replace('(','').replace(')','').replace('{','').replace('}','').replace('[','').replace(']','').replace('"','').replace('$','').replace('%','').replace('+','').replace('!','').replace("'",'').replace('#','').replace('@','')
keywords=[]
for n in range(len(list_of_links)):
    sub_all_text = ""
    url = list_of_links[n]
    try:
        r = requests.get(url, verify = False)
    except:
        print('error occured')
        continue
    soup = BeautifulSoup(r.content, 'lxml')
    match = soup.find_all('div', class_='post-text')

    for i in range(len(match)):
        for j in match[i].find_all('p'):
            sub_all_text+=j.text+" "

    temp_keywords = give_clean_text(sub_all_text).split()
    temp_keywords+=url[url.rindex("/")+1::].split('-')
    temp_keywords = set(temp_keywords)
    file = open("E:\\University_stuff\\semester_3\\data_structures\\end_semester_project\\AnswerBase\\new_new_answers_page.txt", "a", encoding="utf-8")
    for i in temp_keywords:
        if i not in stop_words:
            keywords.append(i)
            file.write(i+" "+url+"\n")
    file.close()
    counter+=1
    print(counter)
    
    #print(keywords)
