# GuestRegistration-4th-semestr-
Курсовой проект за 4 семестр. 

Метод хеширования: Закрытое хеширование с квадратичным опробованием
Метод сортировки: Подсчетом
Вид списка: Линейный однонаправленный
Метод обхода дерева: Прямой
Алгоритм поиска слова в тексте: Боуера и Мура (БМ)

![image](https://user-images.githubusercontent.com/103455085/215851301-5667f742-6c26-4836-bb6b-8181a2d22cfc.png)

Формулировка задания:

 Информационная система для предметной области «Регистрация постояльцев в гостинице» должна осуществлять ввод, хранение, обработку и вывод данных о:
– постояльцах;
– гостиничных номерах;
– вселении и выселении постояльцев.

Данные о каждом постояльце должны содержать:
– Номер паспорта – строка формата «NNNN-NNNNNN», где N –
цифры;
– ФИО – строка;
– Год рождения – целое;
– Адрес – строка;
– Цель прибытия – строка.
Примечание: длина строк (кроме номера паспорта) определяется
студентом самостоятельно.

 Данные о постояльцах должны быть организованны в виде
хеш-таблицы, первичным ключом которой является «номер паспорта» Метод хеширования определяется вариантом задания.

 Данные о каждом гостиничном номере должны содержать:
– Номер гостиничного номера – строка формата «ANNN», где A –
буква, обозначающая тип номера (Л – люкс, П – полулюкс, О – одноместный, М – многоместный); NNN – порядковый номер (цифры);
– Количество мест – целое;
– Количество комнат – целое;
– Наличие санузла – логическое;
– Оборудование – строка.
Примечание: длина строки «Оборудование», содержащая перечень оборудования номера (телевизор, холодильник и пр.), определяется студентом самостоятельно.

 Данные о гостиничных номерах должны быть организованны в виде АВЛ-дерева поиска, упорядоченного по «Номеру гостиничного номера».

Данные о вселении или выселении постояльцев должны
содержать:
– Номер паспорта – строка, формат которой соответствует аналогичной строке в данных о постояльцах;
– Номер гостиничного номера – строка, формат которой соответствует аналогичной строке в данных о гостиничных номерах;
– Дату заселения – строка;
– Дату выселения – строка.
Примечания:
1. Наличие в этих данных записи, содержащей в поле «номер паспорта» значение X и в поле «номер гостиничного номера» значение Y, означает заселение постояльца с номером паспорта X в гостиничный номер Y. Отсутствие такой записи означает, что постоялец
с номером паспорта X не проживает в гостиничном номере Y.
2. В одном гостиничном номере (многоместном) могут проживать
несколько постояльцев. Таким образом, могут быть данные, имеющие повторяющиеся значения в некоторых своих полях.

Данные о вселении или выселении постояльцев должны
быть организованны в виде списка, который упорядочен по первичному ключу – «номер гостиничного номера». Вид списка и метод сортировки определяются вариантом задания.

Информационная система «Регистрация постояльцев в гостинице» должна осуществлять следующие операции:
– регистрацию нового постояльца;
– удаление данных о постояльце;
– просмотр всех зарегистрированных постояльцев;
– очистку данных о постояльцах;
– поиск постояльца по номеру паспорта. Результаты поиска – все
сведения о найденном постояльце и номер гостиничного номера,
в котором он проживает;
– поиск постояльца по ФИО. Результаты поиска – список найденных постояльцев с указанием номера паспорта и ФИО;
– добавление нового гостиничного номера;
– удаление сведений о гостиничном номере;
– просмотр всех имеющихся гостиничных номеров;
– очистку данных о гостиничных номерах;
– поиск гостиничного номера по «номеру гостиничного номера».
Результаты поиска – все сведения о найденном гостиничном номере, а также ФИО и номера паспортов постояльцев, которые вселены
в этот гостиничный номер;
– поиск гостиничного номера по фрагментам «Оборудования».
Результаты поиска – список найденных гостиничных номеров с указанием номера гостиничного номера, количества мест, количества
комнат, оборудования;
– регистрацию вселения постояльца;
– регистрацию выселения постояльца.

Состав данных о постояльцах или гостиничных номерах,
выдаваемых при просмотре всех зарегистрированных постояльцев
или просмотре всех имеющихся гостиничных номеров, определяется студентом самостоятельно, но должен содержать не менее двух
полей.

Метод поиска постояльца по ФИО определяется студентом
самостоятельно. Выбранный метод необходимо сравнить с альтернативными методами.

Поиск гостиничного номера по фрагментам «Оборудования» должен осуществляться путем систематического обхода АВЛдерева поиска. Метод обхода определяется вариантом задания. При
поиске гостиничного номера по фрагментам «Оборудования» могут
быть заданы как полный перечень оборудования гостиничного номера, так и его часть (например, указан только телевизор). Для обнаружения заданного фрагмента в полном перечне оборудования
гостиничного номера должен применяться алгоритм поиска слова
в тексте, указанный в варианте задания.

Регистрация вселения постояльца должна осуществляться только при наличии свободных мест в занимаемом гостиничном
номере.

При удалении данных о постояльце должны быть учтены и обработаны ситуации, когда постоялец заселен в номер. Аналогичным образом следует поступать и с удалением сведений о гостиничном номере.
