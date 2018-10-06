class Stats {
    constructor(array) {
        this.array = array;
    }

    static round(value, round = 2) {
        return Math.round(value * Math.pow(10, round)) / Math.pow(10, round);
    }

    mean() {
        return this.array.reduce((sum, value) => sum + value, 0) / this.array.length;
    }

    median() {
        const arraySorted = this.array.sort();
        return arraySorted.length % 2 === 0 ?
            (arraySorted[arraySorted.length / 2 - 1] + arraySorted[arraySorted.length / 2]) / 2 : arraySorted[Math.floor(arraySorted.length / 2)];
    }

    mode() {
        const table = {};
        this.array.forEach(value => (table[value] = table[value] + 1 || 1));

        let modes = [];
        let max = 0;
        for (const key in table) {
            const value = parseFloat(key);
            const count = table[key];
            if (count > max) {
                modes = [value];
                max = count;
            } else if (count === max) {
                modes.push(value);
            }
        }

        if (modes.length === Object.keys(table).length) {
            modes = [];
        }

        return modes;
    }
}