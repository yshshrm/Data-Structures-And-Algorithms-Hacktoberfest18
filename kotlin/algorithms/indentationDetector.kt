/*
* Если мы хотим уметь обрабатывать ошибки в форматировании документа, необходимо рассматривать весь файл и использовать
* какую-то метрику, которая будет решать, какой отступ является основным, а какой сделан по ошибке
*
* Будем считать не количество строк, имеющих данный отступ, а количество блоков кода, например таких:
* for (symbol in str) {
*     // some code
*     // more code
*     // another line
*     // ...
*     // last
* }
* Тогда, даже если в каком-то блоке программист перепутал размер отступа, это не сильно скажется на всем документе.
* Кроме того, такой подход решает проблему многострочных комментариев, которые часто имеют отступ в 1 пробел
*
* Вкратце о реализации:
*   Будем в каждой строке смотреть разницу размера её отступа и отступа в предыдущей строке. Тогда пример выше даст вклад
*   в общий вес отступа 4 пробелами 2 условные единицы: в начале и в конце блока. Кроме того, запоминаем и сам символ,
*   который использовался для отступа
*
*   Для хранения информации об отступах используется hashMap: {indentSymbol: {indentSize: meetCount}}
*   Это позволяет за один обход документа получить и информацию о символе, использовавшемся для отступа
*
*   После генерации hashMap просто проходим по нему и выбираем самый популярный тип отступа. Это наводит на возможность
*   дальшейшего апгрейда: например, можно выводить вероятность, с которой выведенный символ является верным
* */

import java.io.File
import java.io.FileNotFoundException
import java.io.InputStream
import kotlin.system.exitProcess

// Получает строку документа, возвращает пару (символ, размер отступа)
fun getIndentation(str: String): Pair<Char, Int> {
    var count = 0
    var indentSymbol = ' '
    if (str.isNotEmpty()) {
        indentSymbol = str[0]
    }
    for (symbol in str) {
        if (symbol == indentSymbol) {
            count++
        } else {
            break
        }
    }
    return Pair(indentSymbol, count)
}

fun main(args: Array<String>) {
    if (args.isEmpty()) {
        println("Missing required parameter: filepath")
        return
    }
    val fileName = args[0]
    val inputStream: InputStream
    try {
        inputStream = File(fileName).inputStream()
    } catch (e: FileNotFoundException) {
        println("Error opening file")
        exitProcess(1)
    }

    val indentsTable = hashMapOf(' ' to hashMapOf(0 to 0)) // {indentSymbol: {indentSize: meetCount}}
    var previousIndent = 0
    inputStream.bufferedReader().useLines { lines ->
        lines.forEach {
            val (indentSymbol, currentIndent) = getIndentation(it)
            val diff = Math.abs(previousIndent - currentIndent) // Разница в отступе с предыдущей строкой
            if (diff > 0) {
                // Инкрементируем количество отступов символом indentSymbol и размером diff
                if (indentsTable[indentSymbol] == null) {
                    indentsTable[indentSymbol] = hashMapOf(0 to 0)
                }
                if (indentsTable[indentSymbol]!![diff] != null) {
                    indentsTable[indentSymbol]!![diff] = indentsTable[indentSymbol]!![diff]!! + 1
                } else {
                    indentsTable[indentSymbol]!![diff] = 1
                }
            }
            previousIndent = currentIndent
        }
    }

    // Считаем наиболее часто встречающийся тип отступа
    var maxCount = 0
    var indentSize = 0
    var indentSymbol = ' '
    for (symbol in indentsTable.keys) {
        for (key in indentsTable[symbol]!!.keys) {
            if (indentsTable[symbol]!![key]!! > maxCount) {
                maxCount = indentsTable[symbol]!![key]!!
                indentSize = key
                indentSymbol = symbol
            }
        }
    }

    var indentSymbolPrint = Character.toString(indentSymbol)
    if (indentSymbol == ' ') {
        indentSymbolPrint = "space"
    } else if (indentSymbol == '	') {
        indentSymbolPrint = "tab"
    }
    println("Symbol: '$indentSymbolPrint', size: $indentSize")
}
