const chunk = (array, size) => {
    const chunks = [];

    for (let item of array) {
        const lastChunk = chunks[chunks.length - 1];
        if (!lastChunk || lastChunk.length === size) chunks.push([item]);
        else lastChunk.push(item);
    }

    return chunks;
};