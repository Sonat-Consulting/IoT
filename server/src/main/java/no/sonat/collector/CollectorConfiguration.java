package no.sonat.collector;

import com.fasterxml.jackson.annotation.JsonProperty;
import io.dropwizard.Configuration;
import no.sonat.collector.influx.HasInfluxConfiguration;
import no.sonat.collector.influx.InfluxConfiguration;

/**
 * @author zapodot
 */
public class CollectorConfiguration extends Configuration implements HasInfluxConfiguration {

    @JsonProperty
    public InfluxConfiguration influx;

    @Override
    public InfluxConfiguration getInfluxConfiguration() {
        return influx;
    }
}
